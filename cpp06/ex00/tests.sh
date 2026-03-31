#!/bin/bash

# =============================================================================
# CPP06/ex00 — ScalarConverter TEST SUITE
# =============================================================================

BINARY="./convert"

if [ ! -f "$BINARY" ]; then
    echo "❌ Binary not found: $BINARY"
    exit 1
fi

PASS=0
FAIL=0

GREEN='\033[0;32m'
RED='\033[0;31m'
CYAN='\033[0;36m'
YELLOW='\033[0;33m'
RST='\033[0m'

# -----------------------------------------------------------------------------
header() {
    echo ""
    echo -e "${CYAN}━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━${RST}"
    echo -e "${CYAN}  $1${RST}"
    echo -e "${CYAN}━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━${RST}"
}

# -----------------------------------------------------------------------------
run_test() {
    local desc="$1"
    local input="$2"
    shift 2

    local output
    output=$($BINARY "$input" 2>&1)

    local ok=true
    local failed_patterns=()

    for pattern in "$@"; do
        if ! echo "$output" | grep -q "$pattern"; then
            ok=false
            failed_patterns+=("$pattern")
        fi
    done

    if $ok; then
        echo -e "${GREEN}✔ PASS${RST} — $desc"
        PASS=$((PASS + 1))
    else
        echo -e "${RED}✘ FAIL${RST} — $desc"
        echo -e "${YELLOW}Input:${RST} $input"
        echo -e "${YELLOW}Expected patterns:${RST}"
        for p in "${failed_patterns[@]}"; do
            echo "  - $p"
        done
        echo -e "${YELLOW}Output:${RST}"
        echo "$output"
        FAIL=$((FAIL + 1))
    fi
}

# =============================================================================
# TESTS
# =============================================================================

header "CHAR TESTS"

run_test "simple char" "a" \
"char:.*'a'" \
"int:.*97" \
"float:.*97.*f" \
"double:.*97"

run_test "non displayable char" $'\x01' \
"char:.*Non displayable"

run_test "digit is not char" "1" \
"char:.*Non displayable"


# -----------------------------------------------------------------------------
header "INT TESTS"

run_test "basic int" "42" \
"int:.*42" \
"float:.*42.*f" \
"double:.*42"

run_test "negative int" "-42" \
"int:.*-42"

run_test "int overflow" "2147483648" \
"int:.*impossible"

run_test "int underflow" "-2147483649" \
"int:.*impossible"


# -----------------------------------------------------------------------------
header "FLOAT TESTS"

run_test "basic float" "42.5f" \
"float:.*42\.5f" \
"double:.*42\.5"

run_test "float no decimal" "42f" \
"float:.*42\.0f" \
"double:.*42\.0"

run_test "float with sign" "-3.14f" \
"float:.*-3\.14f"

run_test "float scientific (unsupported)" "1e39f" \
"float:.*nanf" \
"double:.*nan"

# -----------------------------------------------------------------------------
header "DOUBLE TESTS"

run_test "basic double" "42.5" \
"double:.*42\.5"

run_test "double integer format" "42." \
"double:.*42\.0"

run_test "negative double" "-0.001" \
"double:.*-0\.001"

run_test "double scientific (unsupported)" "1e308" \
"double:.*nan"

# -----------------------------------------------------------------------------
header "PSEUDO LITERALS"

run_test "nan" "nan" \
"double:.*nan" \
"float:.*nanf"

run_test "nanf" "nanf" \
"float:.*nanf"

run_test "+inf" "+inf" \
"double:.*\+inf"

run_test "-inf" "-inf" \
"double:.*-inf"

run_test "+inff" "+inff" \
"float:.*\+inff"

run_test "inf" "inf" \
"double:.*\+inf"


# -----------------------------------------------------------------------------
header "INVALID INPUT"

run_test "random string" "hello" \
"double:.*nan" \
"float:.*nanf" \
"int:.*impossible"

run_test "mixed invalid" "42abc" \
"double:.*nan"

run_test "only sign" "+" \
"double:.*nan"

run_test "empty string" "" \
"double:.*nan"


# -----------------------------------------------------------------------------
header "EDGE CASES"

run_test "just dot" "." \
"double:.*nan"

run_test "multiple dots" "1.2.3" \
"double:.*nan"

run_test "signed dot" "-." \
"double:.*nan"

run_test "zero" "0" \
"int:.*0" \
"float:.*0.*f" \
"double:.*0"


# =============================================================================
# SUMMARY
# =============================================================================

echo ""
echo -e "${CYAN}━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━${RST}"
echo -e "${CYAN}  RESULT${RST}"
echo -e "${CYAN}━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━${RST}"

echo -e "${GREEN}Passed:${RST} $PASS"
echo -e "${RED}Failed:${RST} $FAIL"

if [ $FAIL -eq 0 ]; then
    echo -e "${GREEN}All tests passed ✔${RST}"
else
    echo -e "${RED}Some tests failed ✘${RST}"
fi
