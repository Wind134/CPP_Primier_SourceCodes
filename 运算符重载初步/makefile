# executable files for this directory
OBJECTS = add.out add_item.out add_item2.out for_ex.out \
			forcount.out item_io.out \
		  main_only.out mysum.out occurs.out whilecount.out 

# tells make to use the file "../GNU_makefile_template", which
# defines general rules for making .o and .exe files
include ../GNU_makefile_template

# 以下规则代表下面三个可执行文件都依赖于那个头文件，如果头文件更改则需要重新编译
add_item.out add_item2.out item_io.out: Sales_item.h
