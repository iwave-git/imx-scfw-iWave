/^\s*\(DEFINE\) /!d
s/^\s*\(DEFINE\) \([^ ]\+\) *$/\#define \2 /
s/^\s*\(DEFINE\) \([^ ]\+\) \([^ ]\+\) *$/\#define \2 \3U/
