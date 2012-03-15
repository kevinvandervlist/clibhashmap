all:	
	@echo "\n--- Building the library ---\n"
	@cd lib; make; cd ..; 
	@echo "\n--- Building and running the tests ---\n"
	@cd tests; ./generate_makefile.pl > Makefile; make; make run; cd ..; 
	@echo "\n--- Building the demos ---\n"
	@cd demo; make; cd ..

clean:
	@cd lib; make clean; cd ..; 
	@cd tests; make clean; cd ..; 
	@cd demo; make clean; cd ..
