#!/bin/bash

# RTAB-Map Database Cleanup Script
# Removes old RTAB-Map database to ensure clean SLAM starts

DB_PATH="$HOME/.ros/rtabmap.db"

echo "RTAB-Map Database Cleanup"
echo "========================"

if [ -f "$DB_PATH" ]; then
    DB_SIZE=$(du -h "$DB_PATH" | cut -f1)
    echo "Found existing database: $DB_PATH ($DB_SIZE)"
    echo ""
    read -p "Delete old database for clean SLAM start? (y/N): " -n 1 -r
    echo

    if [[ $REPLY =~ ^[Yy]$ ]]; then
        rm -f "$DB_PATH"
        echo "✓ Database removed successfully"
        echo "Next RTAB-Map run will start with clean SLAM"
    else
        echo "Database kept - you may experience position jumps"
    fi
else
    echo "No existing database found - clean start ready"
fi

echo ""
echo "Note: Database will be recreated automatically on next RTAB-Map run"