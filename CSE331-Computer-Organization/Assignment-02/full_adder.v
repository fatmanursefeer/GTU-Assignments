module full_adder (input A, B, Carry_In, output Sum, Carry_Out);

wire w0, w1, w2;

half_adder ha_1 (A, B, w0, w1);
half_adder ha_2 (w0, Carry_In, Sum, w2);

or or1 (Carry_Out, w2, w1);

endmodule
