`define DELAY 20
module mux_8x1_32_bit_testbench();

reg [31:0] In0, In1, In2, In3, In4, In5, In6, In7;
reg [2:0] Op;
wire [31:0] Out;


mux_8x1_32_bit test8x1Mux (In0, In1, In2, In3, In4, In5, In6, In7, Op, Out);



initial begin
In0 = 'd100; In1 = 'd200; In2 = 'd300; In3 = 'd400; In4 = 'd500; In5 = 'd600; In6 = 'd700; In7 = 'd800; Op = 3'b000;
#`DELAY;
In0 = 'd100; In1 = 'd200; In2 = 'd300; In3 = 'd400; In4 = 'd500; In5 = 'd600; In6 = 'd700; In7 = 'd800; Op = 3'b001;
#`DELAY;
In0 = 'd100; In1 = 'd200; In2 = 'd300; In3 = 'd400; In4 = 'd500; In5 = 'd600; In6 = 'd700; In7 = 'd800; Op  = 3'b010;
#`DELAY;
In0 = 'd100; In1 = 'd200; In2 = 'd300; In3 = 'd400; In4 = 'd500; In5 = 'd600; In6 = 'd700; In7 = 'd800; Op = 3'b011;
#`DELAY;
In0 = 'd100; In1 = 'd200; In2 = 'd300; In3 = 'd400; In4 = 'd500; In5 = 'd600; In6 = 'd700; In7 = 'd800; Op = 3'b100;
#`DELAY;
In0 = 'd100; In1 = 'd200; In2 = 'd300; In3 = 'd400; In4 = 'd500; In5 = 'd600; In6 = 'd700; In7 = 'd800; Op = 3'b101;
#`DELAY;
In0 = 'd100; In1 = 'd200; In2 = 'd300; In3 = 'd400; In4 = 'd500; In5 = 'd600; In6 = 'd700; In7 = 'd800; Op = 3'b110;
#`DELAY;
In0 = 'd100; In1 = 'd200; In2 = 'd300; In3 = 'd400; In4 = 'd500; In5 = 'd600; In6 = 'd700; In7 = 'd800; Op = 3'b111;

end
 
 
initial
begin
$monitor("time=%2d, In0=%d, In1=%d, In2=%d, In3=%d, In4=%d, In5=%d, In6=%d, In7=%d,Op=%d, Out=%d", $time, In0,In1,In2,In3,In4,In5,In6,In7,Op,Out);
end
 
endmodule
