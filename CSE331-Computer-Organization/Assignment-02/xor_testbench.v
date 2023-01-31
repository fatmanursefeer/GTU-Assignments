`define DELAY 20
module xor_testbench(); 

reg [31:0] A, B;
wire [31:0] wireXor;

xor_32_bit testXor (A, B, wireXor);

initial begin
A = 32'd642; B = 32'd752;
#`DELAY;
A = 32'd512; B = 32'd635;
#`DELAY;
A = 32'd15; B = 32'd212;
#`DELAY;
A = 32'd40; B = 32'd119;
end
 
 
initial
begin
$monitor("time = %2d, A =%b, B=%b, wireXor=%b", $time, A, B, wireXor);
end
 
endmodule
