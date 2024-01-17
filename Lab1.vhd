library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_unsigned.all;

entity lab1 is
	port (
		clk           : in std_logic ;
		reset         : in std_logic ; -- reset_n
		trigger       : in std_logic;
		speed         : in std_logic_vector (3 downto 0);
		leds          : out std_logic_vector (7 downto 0)
	);
end entity lab1;

architecture behav of lab1 is
    component ga_lab1 is
        port (
            clk_clk                          : in  std_logic                    := 'X';             -- clk
            pio_0_external_connection_export : out std_logic_vector(7 downto 0);                    -- export
            pio_1_external_connection_export : in  std_logic                    := 'X';             -- export
            pio_2_external_connection_export : in  std_logic_vector(3 downto 0) := (others => 'X'); -- export
            reset_reset_n                    : in  std_logic                    := 'X'              -- reset_n
        );
    end component ga_lab1;
		begin
    u0 : component ga_lab1
        port map (
            clk_clk                                 => clk,                                           --                       clk.clk
            reset_reset_n                           => reset,                    --                     reset.reset_n
            pio_2_external_connection_export        => speed,                                         -- pio_2_external_connection.export
            pio_1_external_connection_export        => trigger,                                       -- pio_1_external_connection.export
            pio_0_external_connection_export        => leds                                           -- pio_0_external_connection.export
        );

end architecture behav;
