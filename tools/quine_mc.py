from quine_mccluskey.qm import QuineMcCluskey

def format_set(s):
    """
    Format a set of strings.
    """
    max_el = 50
    if not s:
        return ""
    l = list(s)
    ret = "'" + "', '".join(l[:min(max_el, len(s))]) + "'"
    if len(s) > max_el:
        ret = ret + ", ..."
    return ret

Arith_Min_Terms   = [4,5,12,13,20,21,28,29,36,37,39,44,45,47,52,53,55,60,61,63,128,129,130,131,132,133,134,135,136,137,138,139,140,141,142,143,144,145,146,147,148,149,150,151,152,153,154,155,156,157,158,159,160,161,162,163,164,165,166,167,168,169,170,171,172,173,174,175,176,177,178,179,180,181,182,183,184,185,186,187,188,189,190,191,198,206,214,222,230,238,246,254,3,9,11,19,25,27,35,41,43,51,57,59,232]
Flow_Min_Terms = [24,32,40,48,56,192,194,195,196,199,200,201,202,204,205,207,208,210,212,215,216,217,218,220,223,231,233,239,247,255]
Load_Min_Terms = [2,6,10,14,18,22,26,30,34,38,42,46,50,54,58,62,64,65,66,67,68,69,70,71,72,73,74,75,76,77,78,79,80,81,82,83,84,85,86,87,88,89,90,91,92,93,94,95,96,97,98,99,100,101,102,103,104,105,106,107,108,109,110,111,112,113,114,115,116,117,119,120,121,122,123,124,125,126,127,224,226,234,240,242,250,1,8,17,33,49,193,197,209,213,225,229,241,245,248,249]
Logical_Min_Terms = [7,15,23,31,203]
Misc_Min_Terms = [0,16,118,243,251]

Load_IR_Terms = [6,14,22,30,38,46,62]
Load_RR_Terms = [64,65,66,67,68,69,70,71,72,73,74,75,76,77,78,79,80,81,82,83,84,85,86,87,88,89,90,91,92,93,94,95,96,97,98,99,100,101,102,103,104,105,106,107,108,109,110,111,112,113,114,115,116,117,119,120,121,122,123,124,125,126,127]
POP_Terms = [0xc1, 0xd1, 0xe1, 0xf1]
ADD_Terms = [0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87]
INC_Terms = [0x04,0x14,0x24,0x34,0x0C,0x1C,0x2C,0x3C]
DEC_Terms = [0x05,0x15,0x25,0x35,0x0D,0x1D,0x2D,0x3D]
DINC_T      = [0x03, 0x13, 0x23, 0x33]
DADD_T      = [0x09, 0x19, 0x29, 0x39]
DDEC_T      = [0x0B, 0x1B, 0x2B, 0x3B]

list_of_reductions = {
"Arith_Min_Terms   " : Arith_Min_Terms,
"Flow_Min_Terms    " : Flow_Min_Terms,
"Load_Min_Terms    " : Load_Min_Terms,
"Logical_Min_Terms " : Logical_Min_Terms,
"Misc_Min_Terms    " : Misc_Min_Terms,
"Load_IR_Terms     " : Load_IR_Terms,
"Load_RR_Terms     " : Load_RR_Terms,
"POP_Terms         " : POP_Terms,
"ADD_Terms         " : ADD_Terms,
"INC_TERMS         " : INC_Terms,
"DEC_TERMS         " : DEC_Terms,
"DINC_T            " : DINC_T,
"DADD_T            " : DADD_T,
"DDEC_T            " : DDEC_T
}

qm = QuineMcCluskey(use_xor = False)

for name in list_of_reductions:
    res = qm.simplify(list_of_reductions[name],[])
    print("%25s: [%s]" % (name, format_set(res)))

