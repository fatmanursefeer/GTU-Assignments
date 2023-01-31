module half_adder (input A, B, output Sum, Carry);

xor s1 (Sum, A, B);
and s2 (Carry, A, B);

endmodule
