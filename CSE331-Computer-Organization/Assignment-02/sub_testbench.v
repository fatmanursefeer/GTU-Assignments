`define DELAY 20
module sub_testbench();

reg [31:0] A, B, wBNot;
reg regCarryIn;

wire [31:0] wireSub;
wire wireCarryOut, wireTemp;

not_32_bit notB (B, wBNot);
adder testAdder (A, wBNot, regCarryIn, wireSub, wireCarryOut, wireTemp);


initial begin
A = 32'd25; B = 32'd15; regCarryIn = 1'd1;
#`DELAY;
A = 32'd10; B = 32'd2; regCarryIn = 1'd1;
#`DELAY;
A = 32'd190; B = 32'd25; regCarryIn = 1'd1;
#`DELAY;
A = 32'd9; B = 32'd10; regCarryIn = 1'd1;
#`DELAY;
A = 32'd19; B = 32'd11; regCarryIn = 1'd1;
#`DELAY;
A = 32'd20; B = 32'd40; regCarryIn = 1'd1;
end
 
 
initial
begin
$monitor("time = %2d, A =%d, B=%d, regCarryIn=%d, wireSub=%d, wireCarryOut=%d", $time, A, B, regCarryIn, wireSub, wireCarryOut);
end
 
endmodule
