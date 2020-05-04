import re
import sys

def filter_scope(fh):

    exit_list = (
        "RET",
        "RETI"
    )

    addr_re = re.compile(".*PC:([0-9A-F]{4}).*: ([A-Za-z0-9 ,\(\)]*)")

    known_instructions = []
    output_buffer = ""

    exit_buffer = False

    while(not exit_buffer):
        line = fh.readline()

        if(line == ""):
            return output_buffer

        line = line.upper()

        # print("Checking line %s" % line, end="")

        addr_m = addr_re.match(line)
        if(addr_m == None):
            continue

        new_instr = False

        # If we've never seen the instruction on this scope, add it
        if addr_m.group(1) not in known_instructions:
            # print("New Instruction Detected %s " % addr_m.group(1), end="")
            output_buffer += line
            known_instructions.append(addr_m.group(1))
            new_instr = True

        # If we're doing a call, work through its scope
        if "CALL" in addr_m.group(2):
            # print("Call Detected %s\n" % addr_m.group(2), end="")
            # If the instruction making the call has been seen before, don't
            #  add the output
            new_scope = filter_scope(fh)

            if new_instr:
                # print("New Call Detected %s\n" % addr_m.group(2), end="")
                output_buffer += "\n"
                output_buffer += new_scope
                output_buffer += "\n"

        for criteria in exit_list:
            if criteria in addr_m.group(2):
                # print("Detected Return", end="")
                exit_buffer = True

        # print("")

    return output_buffer

target_trace = "trace_output.txt"

if len(sys.argv) >= 2:
    target_trace = sys.argv[1]

base_name = target_trace[:target_trace.rfind(".")]
out_name = base_name + ".output.txt"

with open(target_trace,'r') as fh:
    with open(out_name,'w') as ofh:
        ofh.write(filter_scope(fh))