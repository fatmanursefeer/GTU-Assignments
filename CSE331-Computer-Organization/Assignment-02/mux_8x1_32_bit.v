module mux_8x1_32_bit (input [31:0] In0, In1, In2, In3, In4, In5, In6, In7, input [2:0] ALUOp, output [31:0] Out);

wire [31:0] w0, w1, w2, w3, w4, w5;

// In here we are using 32 bit 2x1 mux
mux_2x1_32_bit mux0 (In0, In1, ALUOp[0], w0);
mux_2x1_32_bit mux1 (In2, In3, ALUOp[0], w1);
mux_2x1_32_bit mux2 (In4, In5, ALUOp[0], w2);
mux_2x1_32_bit mux3 (In6, In7, ALUOp[0], w3);
mux_2x1_32_bit mux4 (w0, w1, ALUOp[1], w4);
mux_2x1_32_bit mux5 (w2, w3, ALUOp[1], w5);
mux_2x1_32_bit mux6 (w4, w5, ALUOp[2], Out);

endmodule
