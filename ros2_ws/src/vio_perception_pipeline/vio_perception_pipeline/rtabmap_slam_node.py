#!/usr/bin/env python3

import subprocess
import sys
import os

def main():
    # Set library path to use our CUDA/GTSAM RTABMAP
    env = os.environ.copy()
    env['LD_LIBRARY_PATH'] = '/usr/local/lib:' + env.get('LD_LIBRARY_PATH', '')

    # Get RTABMAP command
    cmd = ['/usr/local/bin/rtabmap']

    # Add ROS arguments
    cmd.extend(sys.argv[1:])

    # Execute our CUDA/GTSAM RTABMAP
    try:
        subprocess.run(cmd, env=env, check=True)
    except subprocess.CalledProcessError as e:
        print(f"RTABMAP SLAM failed with exit code {e.returncode}", file=sys.stderr)
        sys.exit(e.returncode)
    except KeyboardInterrupt:
        print("RTABMAP SLAM interrupted", file=sys.stderr)
        sys.exit(130)

if __name__ == '__main__':
    main()