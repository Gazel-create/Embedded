#include "Vmac.h"
#include "verilated.h"
#include "verilated_vcd_c.h"
#include <iostream>

// toggle clock by one edge
void tick(Vmac* top, VerilatedVcdC* tfp, vluint64_t& sim_time) {
	sim_time++;
	top->clk ^= 1;		//flip the clock
	top->eval();		//recompute outputs
	tfp->dump(sim_time);	//record to waveform
}

int main(int argc, char** argv) {
	Verilated::commandArgs(argc, argv);
	Verilated::traceEverOn(true);

	VerilatedVcdC* tfp = new VerilatedVcdC;
	Vmac* top = new Vmac;

	top->trace(tfp, 99);		//link top module tacking
	tfp->open("waveform.vcd");	//create/open the destination wave file
	
	vluint64_t sim_time = 0;

	// -- Initializing all the inputs before the 1st eval() --
	
	top->clk = 0;
	top->reset = 1;
	top->data_in = 0;
	top->weight = 0;
	top->eval();
	tfp->dump(sim_time);

	// Hold reset for 2 full clock cycles (4 edges)
	
	for  (int i = 0; i < 4; i++) {
		tick(top, tfp, sim_time);
	}
	
	// Releases reset
	top->reset = 0;
	top->eval();
	tfp->dump(sim_time);

	//phase 1 5 * 2 = 10 per cycle, for 8 cycles
	//set inputs while clock is low, so they're stable before the rising edge (which causes race condition)
	
	top->data_in = 5;
	top->weight = 2;

	for  (int i = 0; i < 8; i++){
		tick(top, tfp, sim_time); // rising edge
		tick(top, tfp, sim_time); //falling edge
			}

	//phase 2: -3 * 3 = -9 per cycle, for 8 cycles
	
	top->data_in = -3;
	top->weight = 3;

	for (int i = 0; i < 8; i++) {
		tick(top, tfp, sim_time);
		tick(top, tfp, sim_time);
	}

	// cleanup
	
	tfp->close();
	delete top;
	delete tfp;

	std::cout << "Simulation complete. Open waveform.vcd." << std::endl;

	return 0;
}







