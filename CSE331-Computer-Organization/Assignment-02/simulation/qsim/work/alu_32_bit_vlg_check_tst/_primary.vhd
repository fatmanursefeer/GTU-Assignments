library verilog;
use verilog.vl_types.all;
entity alu_32_bit_vlg_check_tst is
    port(
        Result          : in     vl_logic_vector(31 downto 0);
        sampler_rx      : in     vl_logic
    );
end alu_32_bit_vlg_check_tst;
