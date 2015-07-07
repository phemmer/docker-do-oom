#!/bin/bash
set -e

mount -n -t tmpfs -o uid=0,gid=0,mode=0755 cgroup /sys/fs/cgroup
mkdir /sys/fs/cgroup/memory
mount -n -t cgroup -o memory cgroup /sys/fs/cgroup/memory

memcgpath="/sys/fs/cgroup/memory/$(awk -F: '$2 == "memory" { print $3 }' < /proc/$$/cgroup)"
echo 1 > "$memcgpath/memory.oom_control"

exec "$@"
