`define DELAY 20
module mux_2x1_32_bit_testbench();

reg [31:0] A, B;
reg Op;
wire [31:0] Out;

mux_2x1_32_bit testMux32Bit (A, B, Op, Out);

initial begin
A = 'd300; B = 'd100; Op = 1'd1;
#`DELAY;
A = 'd200; B = 'd100; Op = 1'd0;
#`DELAY;
A = 'd10; B = 'd40; Op = 1'd1;
#`DELAY;
A = 'd40; B = 'd10; Op = 1'd1;
end
 
 
initial
begin
$monitor("time = %2d, A =%d, B=%d, Op=%b, Out=%d", $time, A, B, Op, Out);
end
 
endmodule
