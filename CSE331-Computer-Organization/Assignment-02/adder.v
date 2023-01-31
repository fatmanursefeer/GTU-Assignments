module adder (input [31:0] A, B, input Carry_In, output [31:0] Sum, output Carry_Out, Carry_Overflow);

// Carry_Overflow is using for set less than

wire [29:0] w0;

full_adder fa0 (A[0], B[0], Carry_In, Sum[0], w0[0]);
full_adder fa1 (A[1], B[1], w0[0], Sum[1], w0[1]);
full_adder fa2 (A[2], B[2], w0[1], Sum[2], w0[2]);
full_adder fa3 (A[3], B[3], w0[2], Sum[3], w0[3]);
full_adder fa4 (A[4], B[4], w0[3], Sum[4], w0[4]);
full_adder fa5 (A[5], B[5], w0[4], Sum[5], w0[5]);
full_adder fa6 (A[6], B[6], w0[5], Sum[6], w0[6]);
full_adder fa7 (A[7], B[7], w0[6], Sum[7], w0[7]);
full_adder fa8 (A[8], B[8], w0[7], Sum[8], w0[8]);
full_adder fa9 (A[9], B[9], w0[8], Sum[9], w0[9]);
full_adder fa10 (A[10], B[10], w0[9], Sum[10], w0[10]);
full_adder fa11 (A[11], B[11], w0[10], Sum[11], w0[11]);
full_adder fa12 (A[12], B[12], w0[11], Sum[12], w0[12]);
full_adder fa13 (A[13], B[13], w0[12], Sum[13], w0[13]);
full_adder fa14 (A[14], B[14], w0[13], Sum[14], w0[14]);
full_adder fa15 (A[15], B[15], w0[14], Sum[15], w0[15]);
full_adder fa16 (A[16], B[16], w0[15], Sum[16], w0[16]);
full_adder fa17 (A[17], B[17], w0[16], Sum[17], w0[17]);
full_adder fa18 (A[18], B[18], w0[17], Sum[18], w0[18]);
full_adder fa19 (A[19], B[19], w0[18], Sum[19], w0[19]);
full_adder fa20 (A[20], B[20], w0[19], Sum[20], w0[20]);
full_adder fa21 (A[21], B[21], w0[20], Sum[21], w0[21]);
full_adder fa22 (A[22], B[22], w0[21], Sum[22], w0[22]);
full_adder fa23 (A[23], B[23], w0[22], Sum[23], w0[23]);
full_adder fa24 (A[24], B[24], w0[23], Sum[24], w0[24]);
full_adder fa25 (A[25], B[25], w0[24], Sum[25], w0[25]);
full_adder fa26 (A[26], B[26], w0[25], Sum[26], w0[26]);
full_adder fa27 (A[27], B[27], w0[26], Sum[27], w0[27]);
full_adder fa28 (A[28], B[28], w0[27], Sum[28], w0[28]);
full_adder fa29 (A[29], B[29], w0[28], Sum[29], w0[29]);
full_adder fa30 (A[30], B[30], w0[29], Sum[30], Carry_Overflow);
full_adder fa31 (A[31], B[31], Carry_Overflow, Sum[31], Carry_Out);

endmodule
