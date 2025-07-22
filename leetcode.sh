#!/bin/bash

# Ask for problem details
echo "Enter folder name (e.g., arrays, dp, strings):"
read folder
mkdir -p $folder

echo "Enter file name (e.g., TwoSum.cpp):"
read filename

echo "Enter LeetCode Problem Number (e.g., 1):"
read number

echo "Enter LeetCode Problem Name (e.g., Two Sum):"
read problem

# Generate file path
filepath="$folder/$filename"

# Create file with LeetCode link in comments
echo "// LeetCode #$number: $problem" > $filepath
echo "// https://leetcode.com/problems/$(echo $problem | tr '[:upper:]' '[:lower:]' | tr ' ' '-')" >> $filepath
echo "" >> $filepath

# Tell user to start solving
echo "📝 File created at: $filepath"
echo "👉 Open this file in Cursorn to solve the problem."

# Wait for user to finish
read -p "✅ Press Enter once you're done solving to upload to GitHub..."

# Push to GitHub
git add $filepath
git commit -m "Add LeetCode #$number - $problem"
git push origin main
