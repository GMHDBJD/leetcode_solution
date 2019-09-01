#
# @lc app=leetcode id=194 lang=bash
#
# [194] Transpose File
#
# Read from the file file.txt and print its transposed content to stdout.

# hagaomodu

awk '
{
    for (i = 1; i <= NF; i++) {
        if(NR == 1) {
            s[i] = $i;
        } else {
            s[i] = s[i] " " $i;
        }
    }
}
END {
    for (i = 1; s[i] != ""; i++) {
        print s[i];
    }
}' file.txt

