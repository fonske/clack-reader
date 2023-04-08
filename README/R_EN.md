# Clack - Reader

## Lovelace menu
In order to use the front-end as shown here: 
![Example](printscreen.jpg)

You will need to install HACS and the following plugins:

* stack-in-card
* multiple-entity-row
* bar-card
* apexcharts  (Bar Charts)

## Automations
Add the content of [automations.yaml](../automations.yaml) to your current automations file in Home Assistant.
Next up add the content of [clack.yaml](../clack.yaml) to your current configuration file in Home Assistant.

### Custom file location: 
If you want to keep the files seperate you can include them like so:

```yml
homeassistant:
  packages: !include_dir_named packages
```
Now you can create a folder called `packages` in the folder `config` and place the `clack.yaml` there. 

Mare sure to restart HomeAssistant.

## Configuration
### Clack.yaml
You will need to time your clack head (with a stopwatch) and adjust the times in the `clack.yaml` to the time your clack actually takes per step. 

You can see the status of the steps on the display.

### Pictures salt tank
In order to get the salt tank level to display you will need to copy the pictures in the `/www/images` directory to your local `/www/images` directory.

### Relays
The 2 relays that the clack head has still need to be set-up.
* Relay1: Counting of water usage 
* Relay2: Regeneration pulse

You can see on the back of the circuit board where to hook each wire up to makred as `RLY1`, `+COM` and  `RLY2` for this to work these need to be connected in the srew terminals on the right side of the Clack board.
![Schematic](diagram.png)

### Relay Config
Extra document (still in dutch sorry) with info can be found here: [Settings PDF](instelkaart%20clack%20ws1.pdf) or the full english manual here: [Manual](Full-CLACKWS1-Manual.pdf)

1. Press `arrow down` and the `next` button for 5 secconds
2. Press next (softening) is now visible
3. press the `next` button till you see `<rlY 1>` Thange this to `ON` (softening  L)
4. Press `next`
5. Set the value to `2 L` (this gives a pulse every 2 liters)
5. Press `next`
6. set time: 0.01 min
7. Press `next`
8. set  `rlY 2` "time" to on (gives a pulse when regeneration starts)
9. Press `next`
10. set time: 0.01 min
11. press next  2 times and you are done

Good Luck!

## Note:
Mounting the circuitboard with ESP in the Clack housing can be tricky.
To be able to close the Clack reader the Circuitboard will point slightly inwards.

The ESP might come loose when attempting to close the clack head.



