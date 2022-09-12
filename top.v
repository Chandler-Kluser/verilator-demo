module top(
    input in1,
    input in2,
    output out
);

// nand gate
assign out = ~(in1 & in2);

endmodule;
