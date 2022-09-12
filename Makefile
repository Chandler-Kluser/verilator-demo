.PHONY: all lib run clean output

all: Vtop

Vtop:
	verilator -Wall --trace --exe --build -cc top.cpp top.v

lib:
	verilator --cc top.v

run:
	./obj_dir/Vtop

clear:
	rm -rf obj_dir

output:
	gtkwave -A --rcvar 'fontname_signals Cascadia Code PL 24' --rcvar 'fontname_waves Cascadia Code PL 24' output.vcd