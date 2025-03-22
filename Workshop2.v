module Workshop2 (
	input CLOCK_50,
	input [1:0] KEY,
	input [0:0] SW,
	output [9:0] LEDR
	);
		Hardware u0 (
		.clk_clk       (CLOCK_50),       //   clk.clk
		.reset_reset_n (~SW), // reset.reset_n
		.ledr_export   (LEDR),   //  ledr.export
		.key_export    (KEY)     //   key.export
	);



endmodule