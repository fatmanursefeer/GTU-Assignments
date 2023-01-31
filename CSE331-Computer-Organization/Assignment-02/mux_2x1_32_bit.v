module mux_2x1_32_bit (input [31:0] In0, In1, input ALUOp, output [31:0] Out);

// In here we are using 1 bit 2x1 mux
mux_2x1_1_bit mux0 (In0[0], In1[0], ALUOp, Out[0]);
mux_2x1_1_bit mux1 (In0[1], In1[1], ALUOp, Out[1]);
mux_2x1_1_bit mux2 (In0[2], In1[2], ALUOp, Out[2]);
mux_2x1_1_bit mux3 (In0[3], In1[3], ALUOp, Out[3]);
mux_2x1_1_bit mux4 (In0[4], In1[4], ALUOp, Out[4]);
mux_2x1_1_bit mux5 (In0[5], In1[5], ALUOp, Out[5]);
mux_2x1_1_bit mux6 (In0[6], In1[6], ALUOp, Out[6]);
mux_2x1_1_bit mux7 (In0[7], In1[7], ALUOp, Out[7]);
mux_2x1_1_bit mux8 (In0[8], In1[8], ALUOp, Out[8]);
mux_2x1_1_bit mux9 (In0[9], In1[9], ALUOp, Out[9]);
mux_2x1_1_bit mux10 (In0[10], In1[10], ALUOp, Out[10]);
mux_2x1_1_bit mux11 (In0[11], In1[11], ALUOp, Out[11]);
mux_2x1_1_bit mux12 (In0[12], In1[12], ALUOp, Out[12]);
mux_2x1_1_bit mux13 (In0[13], In1[13], ALUOp, Out[13]);
mux_2x1_1_bit mux14 (In0[14], In1[14], ALUOp, Out[14]);
mux_2x1_1_bit mux15 (In0[15], In1[15], ALUOp, Out[15]);
mux_2x1_1_bit mux16 (In0[16], In1[16], ALUOp, Out[16]);
mux_2x1_1_bit mux17 (In0[17], In1[17], ALUOp, Out[17]);
mux_2x1_1_bit mux18 (In0[18], In1[18], ALUOp, Out[18]);
mux_2x1_1_bit mux19 (In0[19], In1[19], ALUOp, Out[19]);
mux_2x1_1_bit mux20 (In0[20], In1[20], ALUOp, Out[20]);
mux_2x1_1_bit mux21 (In0[21], In1[21], ALUOp, Out[21]);
mux_2x1_1_bit mux22 (In0[22], In1[22], ALUOp, Out[22]);
mux_2x1_1_bit mux23 (In0[23], In1[23], ALUOp, Out[23]);
mux_2x1_1_bit mux24 (In0[24], In1[24], ALUOp, Out[24]);
mux_2x1_1_bit mux25 (In0[25], In1[25], ALUOp, Out[25]);
mux_2x1_1_bit mux26 (In0[26], In1[26], ALUOp, Out[26]);
mux_2x1_1_bit mux27 (In0[27], In1[27], ALUOp, Out[27]);
mux_2x1_1_bit mux28 (In0[28], In1[28], ALUOp, Out[28]);
mux_2x1_1_bit mux29 (In0[29], In1[29], ALUOp, Out[29]);
mux_2x1_1_bit mux30 (In0[30], In1[30], ALUOp, Out[30]);
mux_2x1_1_bit mux31 (In0[31], In1[31], ALUOp, Out[31]);

endmodule
