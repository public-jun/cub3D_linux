#!bin/bash


SCRIPT_DIR=$(cd $(dirname $0); pwd)
for filepath in $SCRIPT_DIR/map_file/test1.cub; do
	valgrind --leak-check=full --show-leak-kinds=all --errors-for-leak-kinds=all --error-exitcode=666 ./cub3D $filepath
done

