library verilog;
use verilog.vl_types.all;
entity alu_32_bit is
    port(
        A               : in     vl_logic_vector(31 downto 0);
        B               : in     vl_logic_vector(31 downto 0);
        Mult            : in     vl_logic_vector(31 downto 0);
        ALUOp           : in     vl_logic_vector(2 downto 0);
        Result          : out    vl_logic_vector(31 downto 0)
    );
end alu_32_bit;
