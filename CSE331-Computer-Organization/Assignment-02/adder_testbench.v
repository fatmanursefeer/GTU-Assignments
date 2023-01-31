`define DELAY 20
module adder_testbench();
 
reg [31:0] A, B;
reg regCarryIn;

wire [31:0] wireSum;
wire wireCarryOut, wireTemp;

adder testAdder (A, B, regCarryIn, wireSum, wireCarryOut, wireTemp);

initial begin
A = 32'd25; B = 32'd15; regCarryIn = 1'd0;
#`DELAY;
A = 32'd10; B = 32'd2; regCarryIn = 1'd0;
#`DELAY;
A = 32'd190; B = 32'd25; regCarryIn = 1'd0;
#`DELAY;
A = 32'd0; B = 32'd10; regCarryIn = 1'd0;
#`DELAY;
A = 32'd19; B = 32'd11; regCarryIn = 1'd0;
#`DELAY;
A = 32'd20; B = 32'd40; regCarryIn = 1'd0;
end
 
 
initial
begin
$monitor("time = %2d, A =%d, B=%d, regCarryIn=%d, wireSum=%d, wireCarryOut=%d", $time, A, B, regCarryIn, wireSum, wireCarryOut);
end
 
endmodule
