#!/bin/bash
# A simple test script for the Harl program

# Compile if needed
if [ -f "Makefile" ]; then
    echo "🧱 Compiling project..."
    make re > /dev/null 2>&1 || { echo "❌ Compilation failed"; exit 1; }
elif [ ! -x "./harl" ]; then
    echo "⚠️ No Makefile found and ./harl not executable"
    exit 1
fi

# Define test cases
TEST_CASES=(
    ""                      # No argument
    "DEBUG"
    "INFO"
    "WARNING"
    "ERROR"
    "debug"                 # lowercase test
    "SomethingRandom"
    "DEBUG INFO"            # multiple args (invalid)
    "   DEBUG   "           # spaces
)

echo "🚀 Starting tests..."
echo "----------------------------"

for case in "${TEST_CASES[@]}"; do
    echo
    echo "🧪 Test case: '$case'"
    echo "----------------------------"
    if [ -z "$case" ]; then
        ./harl
    else
        ./harl $case
    fi
    echo "----------------------------"
done

echo
echo "✅ All tests completed!"
