/**
 *    Copyright (C) 2020-present MongoDB, Inc.
 *
 *    This program is free software: you can redistribute it and/or modify
 *    it under the terms of the Server Side Public License, version 1,
 *    as published by MongoDB, Inc.
 *
 *    This program is distributed in the hope that it will be useful,
 *    but WITHOUT ANY WARRANTY; without even the implied warranty of
 *    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *    Server Side Public License for more details.
 *
 *    You should have received a copy of the Server Side Public License
 *    along with this program. If not, see
 *    <http://www.mongodb.com/licensing/server-side-public-license>.
 *
 *    As a special exception, the copyright holders give permission to link the
 *    code of portions of this program with the OpenSSL library under certain
 *    conditions as described in each individual source file and distribute
 *    linked combinations including the program with the OpenSSL library. You
 *    must comply with the Server Side Public License in all respects for
 *    all of the code used other than as permitted herein. If you modify file(s)
 *    with this exception, you may extend this exception to your version of the
 *    file(s), but you are not obligated to do so. If you do not wish to do so,
 *    delete this exception statement from your version. If you delete this
 *    exception statement from all source files in the program, then also delete
 *    it in the license file.
 */

#include "mongo/platform/basic.h"

#include "cst_visitor.h"

#include "mongo/db/pipeline/document_source_project.h"
#include "mongo/db/pipeline/document_source_union_with.h"
#include "mongo/db/query/parser/cst_node.h"

namespace mongo {

void CSTPipelineVisitor::visit(CSTNodeProject* projectNode) {
    // auto projectStage =
    //     DocumentSourceProject::create(projectNode->_spec, _expCtx, projectNode->_stageName);
    // _translatedPipeline->pushBack(std::move(projectStage));
}

void CSTPipelineVisitor::visit(CSTNodeUnion* unionNode) {
    // First visit union's sub-pipeline.
    auto unionExpCtx = _expCtx->copyWith(NamespaceString(_expCtx->ns.db(), unionNode->_coll));
    CSTPipelineVisitor subPipelineVisitor(unionExpCtx);
    for (auto node : unionNode->_pipeline) {
        node->acceptVisitor(&subPipelineVisitor);
    }

    // Build the union DocumentSource.
    auto unionStage = make_intrusive<DocumentSourceUnionWith>(
        unionExpCtx, std::move(subPipelineVisitor.releasePipeline()));
    _translatedPipeline->pushBack(std::move(unionStage));
}

}  // namespace mongo
