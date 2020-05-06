rm -rf mongoAgg-gen/*
java -Xmx500M -cp "/usr/local/lib/antlr-4.8-complete.jar" org.antlr.v4.Tool -Dlanguage=Cpp MongoAgg.g4 -visitor -o mongoAgg-gen/
