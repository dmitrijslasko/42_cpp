#!/bin/bash
# =============================================================================
# Tests for CPP06/ex00 - ScalarConverter
# =============================================================================

cd "$(dirname "$0")" || exit 1

BINARY="./convert"
PASS=0
FAIL=0

GREEN='\033[0;32m'
RED='\033[0;31m'
CYAN='\033[0;36m'
RST='\033[0m'

# Label columns padded to WIDTH=20 (matches ScalarConverter::WIDTH)
# "char: "   = 6 chars  → 14 trailing spaces → 20 total
# "int: "    = 5 chars  → 15 trailing spaces → 20 total
# "float: "  = 7 chars  → 13 trailing spaces → 20 total
# "double: " = 8 chars  → 12 trailing spaces → 20 total
C="char:               "
I="int:                "
F="float:              "
D="double:             "

header() {
    echo ""
    echo -e "${CYAN}━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━${RST}"
    echo -e "${CYAN}  $1${RST}"
    echo -e "${CYAN}━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━${RST}"
}

# run_test DESC INPUT PATTERN [PATTERN ...]
# Checks that every PATTERN appears verbatim in the program's output.
run_test() {
    local desc="$1"
    local input="$2"
    shift 2

    local output
    output=$($BINARY "$input" 2>&1)

    local all_pass=true
    local failed=()
    for pat in "$@"; do
        if ! echo "$output" | grep -qF "$pat"; then
            all_pass=false
            failed+=("$pat")
        fi
    done

    if $all_pass; then
        echo -e "  ${GREEN}✓${RST} $desc"
        ((PASS++))
    else
        echo -e "  ${RED}✗${RST} $desc  [input: '$input']"
        echo "$output" | sed 's/^/      /'
        for fp in "${failed[@]}"; do
            echo -e "    ${RED}missing:${RST} $(printf '%q' "$fp")"
        done
        ((FAIL++))
    fi
}

# run_test_exit DESC INPUT EXPECTED_EXIT [PATTERN]
# Checks exit code and, optionally, that PATTERN appears in output.
run_test_exit() {
    local desc="$1"
    local input="$2"
    local expected_exit="$3"
    local pat="${4:-}"

    local output
    output=$($BINARY "$input" 2>&1)
    local exit_code=$?

    local ok=true
    [ "$exit_code" -ne "$expected_exit" ] && ok=false
    if [ -n "$pat" ] && ! echo "$output" | grep -qF "$pat"; then
        ok=false
    fi

    if $ok; then
        echo -e "  ${GREEN}✓${RST} $desc"
        ((PASS++))
    else
        echo -e "  ${RED}✗${RST} $desc  [input: '$input', exit=$exit_code expected=$expected_exit]"
        echo "$output" | sed 's/^/      /'
        ((FAIL++))
    fi
}

# =============================================================================
# Build
# =============================================================================
header "Build"
if make re > /dev/null 2>&1; then
    echo -e "  ${GREEN}✓${RST} Build succeeded"
else
    echo -e "  ${RED}✗${RST} Build failed — aborting"
    exit 1
fi

# =============================================================================
# Char literals  (single printable non-digit character)
# =============================================================================
header "Char literals"
run_test "'a'"  "a"  "${C}'a'"  "${I}97"   "${F}97.0f"   "${D}97.0"
run_test "'A'"  "A"  "${C}'A'"  "${I}65"   "${F}65.0f"   "${D}65.0"
run_test "' '"  " "  "${C}' '"  "${I}32"   "${F}32.0f"   "${D}32.0"
run_test "'!'"  "!"  "${C}'!'"  "${I}33"   "${F}33.0f"   "${D}33.0"
run_test "'~'"  "~"  "${C}'~'"  "${I}126"  "${F}126.0f"  "${D}126.0"
# '+' '-' '.' are single printable non-digit chars — must be treated as char
run_test "'+' (ASCII 43)"  "+"  "${C}'+'"  "${I}43"  "${F}43.0f"  "${D}43.0"
run_test "'-' (ASCII 45)"  "-"  "${C}'-'"  "${I}45"  "${F}45.0f"  "${D}45.0"
run_test "'.' (ASCII 46)"  "."  "${C}'.'"  "${I}46"  "${F}46.0f"  "${D}46.0"
# Single digit must NOT be treated as char (isChar rejects digits)
run_test "'5' → classified as int, not char"  "5"  "${I}5"  "${F}5.0f"  "${D}5.0"

# =============================================================================
# Integer literals
# =============================================================================
header "Integer literals"
run_test "0   (Non displayable char)"  "0"   "${C}Non displayable"  "${I}0"    "${F}0.0f"    "${D}0.0"
run_test "1   (Non displayable char)"  "1"   "${C}Non displayable"  "${I}1"    "${F}1.0f"    "${D}1.0"
run_test "42  (char '*')"              "42"  "${C}'*'"              "${I}42"   "${F}42.0f"   "${D}42.0"
run_test "65  (char 'A')"             "65"  "${C}'A'"              "${I}65"   "${F}65.0f"   "${D}65.0"
run_test "127 (Non displayable char)" "127" "${C}Non displayable"  "${I}127"  "${F}127.0f"  "${D}127.0"
# INT_MAX / INT_MIN boundary
run_test "INT_MAX  2147483647"   "2147483647"   "${C}impossible"  "${I}2147483647"
run_test "INT_MIN -2147483648"   "-2147483648"                    "${I}-2147483648"
# One past the limits — char and int both impossible
run_test "INT_MAX+1  2147483648"  "2147483648"   "${C}impossible"  "${I}impossible"
run_test "INT_MIN-1 -2147483649"  "-2147483649"  "${C}impossible"  "${I}impossible"
# Way out of range
run_test "9999999999 (char+int impossible)"  "9999999999"  "${C}impossible"  "${I}impossible"

# =============================================================================
# Float literals  (must end with 'f' and contain a dot)
# =============================================================================
header "Float literals"
run_test "0.0f"      "0.0f"      "${C}Non displayable"  "${I}0"   "${F}0.0f"     "${D}0.0"
run_test "4.2f"      "4.2f"      "${C}Non displayable"  "${I}4"   "${F}4.2f"     "${D}4.2"
run_test "-4.2f"     "-4.2f"                            "${I}-4"  "${F}-4.2f"    "${D}-4.2"
run_test "42.42f"    "42.42f"    "${C}'*'"              "${I}42"  "${F}42.42f"   "${D}42.42"
run_test "1.23456f"  "1.23456f"                         "${I}1"   "${F}1.23456f" "${D}1.23456"
# Precision preserved: 3 decimals
run_test "0.001f (3 decimals)"  "0.001f"  "${F}0.001f"  "${D}0.001"

# =============================================================================
# Double literals  (contains a dot, no trailing 'f')
# =============================================================================
header "Double literals"
run_test "0.0"      "0.0"      "${C}Non displayable"  "${I}0"   "${F}0.0f"     "${D}0.0"
run_test "4.2"      "4.2"      "${C}Non displayable"  "${I}4"   "${F}4.2f"     "${D}4.2"
run_test "-4.2"     "-4.2"                            "${I}-4"  "${F}-4.2f"    "${D}-4.2"
run_test "42.42"    "42.42"    "${C}'*'"              "${I}42"  "${F}42.42f"   "${D}42.42"
run_test "1.23456"  "1.23456"                         "${I}1"   "${F}1.23456f" "${D}1.23456"
run_test "0.001 (3 decimals)"  "0.001"  "${F}0.001f"  "${D}0.001"

# =============================================================================
# Pseudo-float literals  { nanf, +inff, -inff, inff }
# =============================================================================
header "Pseudo-float literals"
run_test "nanf"   "nanf"   "${C}impossible"  "${I}impossible"  "${F}nanf"   "${D}nan"
run_test "+inff"  "+inff"  "${C}impossible"  "${I}impossible"  "${F}+inff"  "${D}+inf"
run_test "-inff"  "-inff"  "${C}impossible"  "${I}impossible"  "${F}-inff"  "${D}-inf"
run_test "inff"   "inff"   "${C}impossible"  "${I}impossible"  "${F}+inff"  "${D}+inf"

# =============================================================================
# Pseudo-double literals  { nan, +inf, -inf, inf }
# =============================================================================
header "Pseudo-double literals"
run_test "nan"   "nan"   "${C}impossible"  "${I}impossible"  "${F}nanf"   "${D}nan"
run_test "+inf"  "+inf"  "${C}impossible"  "${I}impossible"  "${F}+inff"  "${D}+inf"
run_test "-inf"  "-inf"  "${C}impossible"  "${I}impossible"  "${F}-inff"  "${D}-inf"
run_test "inf"   "inf"   "${C}impossible"  "${I}impossible"  "${F}+inff"  "${D}+inf"

# =============================================================================
# Invalid literals  — must exit 1 and print "Invalid literal"
# =============================================================================
header "Invalid literals (must exit 1)"
run_test_exit "'hello'"      "hello"   1  "Invalid literal"
run_test_exit "'abc'"        "abc"     1  "Invalid literal"
run_test_exit "'1.2.3'"      "1.2.3"   1  "Invalid literal"
run_test_exit "'a1'"         "a1"      1  "Invalid literal"
run_test_exit "'1f' (no dot)" "1f"     1  "Invalid literal"
run_test_exit "'1.0.0f'"     "1.0.0f"  1  "Invalid literal"
run_test_exit "empty string" ""        1

# =============================================================================
# Argument handling
# =============================================================================
header "Argument handling"
output=$(./convert 2>&1); exit_code=$?
if [ "$exit_code" -ne 0 ] && echo "$output" | grep -qiF "usage"; then
    echo -e "  ${GREEN}✓${RST} No arguments → usage message + error exit"
    ((PASS++))
else
    echo -e "  ${RED}✗${RST} No arguments → expected usage message and non-zero exit (got $exit_code)"
    ((FAIL++))
fi

if ./convert a b > /dev/null 2>&1; then
    echo -e "  ${RED}✗${RST} Two arguments → expected non-zero exit"
    ((FAIL++))
else
    echo -e "  ${GREEN}✓${RST} Two arguments → non-zero exit"
    ((PASS++))
fi

# =============================================================================
# Type-detection checks  (the "Is X:" lines printed before conversion)
# =============================================================================
header "Type-detection display"

check_detection() {
    local desc="$1"
    local input="$2"
    local key="$3"      # e.g. "Is char:"
    local expected="$4" # "true" or "false"

    local output
    output=$($BINARY "$input" 2>&1)
    local line
    line=$(echo "$output" | grep -F "$key")

    if echo "$line" | grep -q "$expected"; then
        echo -e "  ${GREEN}✓${RST} $desc"
        ((PASS++))
    else
        echo -e "  ${RED}✗${RST} $desc  [input: '$input']"
        echo -e "    line: $line"
        ((FAIL++))
    fi
}

check_detection "'a' is char"           "a"     "Is char:"         "true"
check_detection "'a' is not int"        "a"     "Is int:"          "false"
check_detection "42 is int"             "42"    "Is int:"          "true"
check_detection "42 is not char"        "42"    "Is char:"         "false"
check_detection "4.2f is float"         "4.2f"  "Is float:"        "true"
check_detection "4.2f is not double"    "4.2f"  "Is double:"       "false"
check_detection "4.2 is double"         "4.2"   "Is double:"       "true"
check_detection "4.2 is not float"      "4.2"   "Is float:"        "false"
check_detection "nanf is pseudo-float"  "nanf"  "Is pseudo-float:" "true"
check_detection "nan is pseudo-double"  "nan"   "Is pseudo-double:" "true"

# =============================================================================
# Summary
# =============================================================================
TOTAL=$((PASS + FAIL))
echo ""
echo -e "${CYAN}━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━${RST}"
if [ "$FAIL" -eq 0 ]; then
    echo -e "  ${GREEN}All $TOTAL tests passed!${RST}"
else
    echo -e "  ${GREEN}$PASS${RST}/${TOTAL} passed   ${RED}$FAIL failed${RST}"
fi
echo -e "${CYAN}━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━${RST}"


# ./convert 7231321321321312323223231312321312489123892183981934821948592183901289038904180922132198491289342819548902183901289054182903890128301283901289032189038129085490123839012890381290481209839012839081290381209481290859012830912839081290381290389012839021830921839012809382190382190830129830912830918213981290481209839021839081290589102830912839081293821938219038902183902