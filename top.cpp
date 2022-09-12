#include <stdlib.h>
#include <iostream>
#include <verilated.h>
#include <verilated_vcd_c.h>
#include "obj_dir/Vtop.h"

vluint64_t sim_time = 0;

int main() {
    Vtop* dut = new Vtop;
    Verilated::traceEverOn(true);
    VerilatedVcdC* m_trace = new VerilatedVcdC;
    dut->trace(m_trace,5);
    m_trace->open("output.vcd");
    while(sim_time<=40){
        dut->in1^=1;
        dut->in2^=dut->in1;
        dut->eval();
        m_trace->dump(sim_time);
        sim_time++;
    }
    m_trace->close();
    delete dut;
    exit(EXIT_SUCCESS);
    return 0;
}
