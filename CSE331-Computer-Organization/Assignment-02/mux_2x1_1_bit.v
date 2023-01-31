module mux_2x1_1_bit (input In0, In1, ALUOp, output  Out);

wire w0, w1, w2;

not not0 (w0, ALUOp);
and and0 (w1, In0, w0);
and and1 (w2, In1, ALUOp);
or or0 (Out, w1, w2);

endmodule
