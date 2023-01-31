library verilog;
use verilog.vl_types.all;
entity alu_32_bit_vlg_sample_tst is
    port(
        A               : in     vl_logic_vector(31 downto 0);
        ALUOp           : in     vl_logic_vector(2 downto 0);
        B               : in     vl_logic_vector(31 downto 0);
        Mult            : in     vl_logic_vector(31 downto 0);
        sampler_tx      : out    vl_logic
    );
end alu_32_bit_vlg_sample_tst;
