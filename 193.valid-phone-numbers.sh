#
# @lc app=leetcode id=193 lang=bash
#
# [193] Valid Phone Numbers
#
# Read from the file file.txt and output all valid phone numbers to stdout.

# hagaomodu

grep -P '^(\d{3}-|\(\d{3}\) )\d{3}-\d{4}$' file.txt

