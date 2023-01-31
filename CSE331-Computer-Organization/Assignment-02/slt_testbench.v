`define DELAY 20
module slt_testbench();

reg [31:0] A, B, wBNot;
reg regCarryIn;
wire [31:0] wireAdd, wireOutSlt, wOutSlt;
wire wireCarryOut, wireTemp, wSlt, wireOSlt;

not_32_bit not3 (B, wBNot);

adder add0 (A, wBNot, regCarryIn, wireAdd, wireCarryOut, wireTemp);
xor xor2 (wSlt, wireCarryOut, wireTemp);
xor xor3 (wireOSlt, wSlt, wireAdd[31]);
or or2 (wireOutSlt[0], wireOSlt, 1'b0);
or_32_bit or3 ({32{1'b0}}, wireOutSlt, wOutSlt);


initial begin
A = 32'd25; B = 32'd15; regCarryIn = 1'd1;
#`DELAY;
A = 32'd10; B = 32'd2; regCarryIn = 1'd1;
#`DELAY;
A = 32'd190; B = 32'd25; regCarryIn = 1'd1;
#`DELAY;
A = 32'd9; B = 32'd10; regCarryIn = 1'd1;
#`DELAY;
A = 32'd9; B = 32'd11; regCarryIn = 1'd1;
#`DELAY;
A = 32'd20; B = 32'd40; regCarryIn = 1'd1;
end
 
 
initial
begin
$monitor("time=%2d,A =%d,B=%d,Out=%d", $time, A, B, wOutSlt);
end
 
endmodule

