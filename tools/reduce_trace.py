import re


addr_re = re.compile(".*PC:([0-9A-F]{4}).*: ([A-Za-z0-9 ,\(\)]*)")

instruction_freq = 

with open("../trace_output.txt",'r') as fh:
    with open("../reduced_trace_output.txt", 'r')