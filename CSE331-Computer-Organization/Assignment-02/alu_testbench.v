`define DELAY 20
module alu_testbench();

reg [31:0] A, B, Mult;
reg [2:0] ALUOp;
wire [31:0] Out;

alu_32_bit testAlu (A, B, Mult, ALUOp, Out);

initial begin
A = 32'd5327; B = 32'd1000; ALUOp = 3'b000; //add
#`DELAY;
A = 32'd53; B = 32'd25; ALUOp = 3'b001; //sub
#`DELAY;
//mult
A = 32'b1011010101000111101; B = 32'b1101011011011101001001; ALUOp = 3'b011; //xor
#`DELAY;
A = 32'b10101100110100101101; B = 32'b01011010101101100; ALUOp = 3'b100; //and
#`DELAY
A = 32'b1011010101000111101; B = 32'b1101011011011101001001; ALUOp = 3'b101; //or
#`DELAY;
A = 32'd300; B = 32'd90; ALUOp = 3'b110; //slt
#`DELAY;
A = 32'b1011101010111000; B = 32'b1011010101101101; ALUOp = 3'b111; //nor
end
 
 
initial
begin
$monitor("Results:time=%d,A=%d,B=%d,ALUOp=%d,Out=%d",$time,A,B,ALUOp,Out);
end
 
endmodule