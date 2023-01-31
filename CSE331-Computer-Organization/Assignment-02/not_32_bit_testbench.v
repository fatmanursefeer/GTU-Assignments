`define DELAY 20
module not_32_bit_testbench(); 

reg [31:0] A;
wire [31:0] Out;

not_32_bit testNot (A, Out);

initial begin
A = 32'd101;
#`DELAY;
A = 32'd999;
#`DELAY;
A = 32'd5253;
#`DELAY;
A = 32'd912331;
#`DELAY;
A = 32'd11;
end
 
 
initial
begin
$monitor("time = %2d, A =%32b, Out=%32b", $time, A, Out);
end
 
endmodule