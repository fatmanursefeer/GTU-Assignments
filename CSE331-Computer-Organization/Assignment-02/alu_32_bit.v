module alu_32_bit (input [31:0] A, B, Mult, input [2:0] ALUOp, output [31:0] Result);

wire [31:0] muxAddMult, muxBorBnot, w1, w2, wBNot; 
wire [31:0] wireAdd, wireMult, wireXor, wireAnd, wireOr, wireNor, wireOutSlt, wOutSlt;
wire [3:0] w0;
wire [1:0] wForAdderCarrys;
wire w3, w4, w5, w6, w7, w8, w9, wCarryIn, wSlt, wireOSlt;

// this section for only adder transactions
not not0 (w3, ALUOp[0]);
not not1 (w4, ALUOp[1]);
not not2 (w5, ALUOp[2]);
xor xor0 (w6, ALUOp[1], ALUOp[2]);
and and0 (w7, w5, w4, ALUOp[0]);
and and1 (w8, ALUOp[2], ALUOp[1], w3);
or or0 (w9, w7, w8);

not_32_bit not3 (B, wBNot);

mux_2x1_32_bit mux0 (A, Mult, w6, muxAddMult);
mux_2x1_32_bit mux1 (B, wBNot, w9, muxBorBnot);
mux_2x1_1_bit mux2 (1'b0, 1'b1, w9, wCarryIn);

// In here we use only one adder for adder, sub, slt and mult
adder add0 (muxAddMult, muxBorBnot, wCarryIn, wireAdd, wForAdderCarrys[0], wForAdderCarrys[1]);
xor xor2 (wSlt, wForAdderCarrys[0], wForAdderCarrys[1]);
xor xor3 (wireOSlt, wSlt, wireAdd[31]);
or or2 (wireOutSlt[0], wireOSlt, 1'b0);
or_32_bit or3 ({32{1'b0}}, wireOutSlt, wOutSlt);
//mult
xor_32_bit xor1 (A, B, wireXor);
and_32_bit and2 (A, B, wireAnd);
or_32_bit or1 (A, B, wireOr);
nor_32_bit nor0 (A, B, wireNor);

// We are sending these wires and it is continue according to ALUOp
mux_8x1_32_bit mux3 (wireAdd, wireAdd, wireAdd, wireXor, wireAnd, wireOr, wOutSlt, wireNor, ALUOp, Result);

endmodule
