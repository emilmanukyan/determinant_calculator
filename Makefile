#this target will compile the program
all:
	@echo "Compiling program..."
	g++ Determinant.cpp -o Det

#this target will run the program
run:
	@echo "Running..."
	./Det

#this target will delete executable file
clean:
	@echo "Deleting executable files..."
	rm -rf *o Det
