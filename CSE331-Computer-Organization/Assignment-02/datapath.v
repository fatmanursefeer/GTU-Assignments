module datapath(
	input wr_multiplicand,
	input wr_product,
	input wr_iteration,
	input sl_add_shift,
	input sl_input,
	input sl_iteration,
	input [31:0] multiplicand, multiplier,
	input clock,
	output stop,
	output [63:0] product);
	
reg [63:0] reg_product;
reg [31:0] reg_multiplicand;
reg [31:0] reg_multiplier;
reg [5:0] reg_iteration;

wire [63:0] w_comp;
wire [63:0] w_adder;
wire [63:0] w_shift;
wire [63:0] w_product;
wire [63:0] w_alpha;
wire [5:0] w_iteration;
wire [5:0] w_itsum;

assign w_adder 	= {reg_product[63:32] + reg_multiplicand, reg_product[31:0]};
assign w_comp 		= {32'd0, multiplier};
assign w_shift 	= reg_product >> 1;
assign w_itsum 	= reg_iteration + 6'd1;
assign product		= reg_product;
assign stop 		= reg_iteration >= 32;

/*MUXes*/
assign w_alpha 		= sl_add_shift ? w_shift : w_adder;
assign w_product 		= sl_input ? w_comp : w_alpha;
assign w_iteration 	= sl_iteration ? w_itsum : 6'd0;

/*Registers*/
always @ (posedge clock) begin
	if(wr_multiplicand)
		reg_multiplicand <= multiplicand;
	if(wr_product)
		reg_product <= w_product;
	if(wr_iteration)
		reg_iteration <= w_iteration;
end

endmodule