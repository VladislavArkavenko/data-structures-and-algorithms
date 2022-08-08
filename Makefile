all: compile execute

compile:
	@echo "Compiling..."
	@clang recursion.c -o program

execute:
	@echo "Executing..."
	@./program

clean:
	@echo "Cleaning..."
	@rm ./program
