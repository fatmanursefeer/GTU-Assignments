`define DELAY 20
module alu_testbench(); 
reg [31:0] a, b;
reg [2:0] aluOP;
wire [31:0] res;

alu atb(a,b,aluOP,res);

initial begin
a = 32'd0; b = 32'hFFFFFFFF; aluOP = 3'b000; //add
#`DELAY;
a = 32'd5327; b = 32'd1000; aluOP = 3'b000; //add
#`DELAY;
a = 32'b1011000111000111101; b = 32'b0101110011011101101101; aluOP = 3'b001; //xor
#`DELAY;
a = 32'd0; b = 32'hFFFFFFFF; aluOP = 3'b001; //xor
#`DELAY;
a = 32'd53; b = 32'd25; aluOP = 3'b010; //sub
#`DELAY;
a = 32'd1000; b = 32'd501; aluOP = 3'b010; //sub
#`DELAY;
a = 32'd10; b = 32'd5; aluOP = 3'b011; //mult
#`DELAY;
a = 32'd1000; b = 32'd3000; aluOP = 3'b100; //slt
#`DELAY;
a = 32'd2000; b = 32'd15; aluOP = 3'b100; //slt
#`DELAY;
a = 32'b1011001010111000; b = 32'b1011000101101101; aluOP = 3'b101; //nor
#`DELAY;
a = 32'hFFFFFFFF; b = 32'd0; aluOP = 3'b101; //nor
#`DELAY;
a = 32'b10101100010101101101; b = 32'b11011010001101100; aluOP = 3'b110; //and
#`DELAY;
a = 32'hFFFFFFFF; b = 32'd0; aluOP = 3'b110; //and
#`DELAY;
a = 32'b1010101010111101101; b = 32'b110101011100; aluOP = 3'b111; //or
#`DELAY;
a = 32'hFFFFFFFF; b = 32'd0; aluOP = 3'b111; //or
end
 
 
initial
begin
$monitor("Results:time=%d,a=%d,b=%d,aluOp=%d,res=%d",$time,a,b,aluOP,res);
end
 
endmodule