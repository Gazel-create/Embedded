module mac (
	input logic	clk,  			//27MHz
	input logic	reset,			//lever to clean memory
	input logic signed [7:0] data_in,	//8-bit
	input logic signed [7:0] weight, 	//8-bit
	output logic signed [15:0] sum_out //16 bit running total
	);

	//Block triggered only when clock ticks up (posedge)
	always_ff @(posedge clk) begin
		if (reset) begin
			sum_out <= 0;
		end else begin
			sum_out <= sum_out + (data_in * weight);
		end
	end
endmodule
