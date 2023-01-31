`define DELAY 20

module mux_2x1_1_bit_testbench(); 

reg A, B, Op;
wire Out;

mux_2x1_1_bit testMux1Bit (A, B, Op, Out);

initial begin
A = 1'b0; B = 1'b0; Op = 1'd0;
#`DELAY;
A = 1'b0; B = 1'b1; Op = 1'd1;
#`DELAY;
A = 1'b1; B = 1'b0; Op = 1'd0;
#`DELAY;
A = 1'b1; B = 1'b1; Op = 1'd0;
#`DELAY;
A = 1'b1; B = 1'b1; Op = 1'd1;
#`DELAY;
A = 1'b0; B = 1'b0; Op = 1'd1;
end
 
 
initial
begin
$monitor("time = %2d, A =%b, B=%b, Op=%b, Out=%b", $time, A, B, Op, Out);
end
 
endmodule
