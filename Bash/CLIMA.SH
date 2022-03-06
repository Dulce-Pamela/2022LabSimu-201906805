#!/bin/bash
touch clima
curl wttr.in/Guatemala >> clima && head -n 7 clima
rm clima
