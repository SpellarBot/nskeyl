.PHONY : all
all : nskeyld nskeyls


nskeyld:
	cc src/nskeyld.c deps/mongoose-master/mongoose.c -o bin/nskeyld

nskeyls:
	cc src/nskeyls.c deps/mongoose-master/mongoose.c -o bin/nskeyls
