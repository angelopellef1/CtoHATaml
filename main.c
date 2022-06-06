/**
* main.c
*/


#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
/*
- id: '1637227129978'
  alias: Entro in Casa
  description: ''
  trigger:
  - platform: state
    entity_id: binary_sensor.door_window_sensor_158d0003139cdd_portaingresso
    from: 'off'
    to: 'on'
  condition:
  - condition: state
    entity_id: binary_sensor.motion_sensor_158d0002b752d9
    state: 'off'
    for:
      hours: 0
      minutes: 30
      seconds: 0
      milliseconds: 0
  - condition: time
    after: '16:00'
    before: 08:00
  action:
  - type: turn_on
    device_id: 46efa8e285c66c17e640b34c7dd62704
    entity_id: light.yeelight_color_0x5384845
    domain: light
  - type: turn_on
    device_id: f7b1e9fa67253a2705eb5a8ac27a0ea3
    entity_id: light.yeelight_color_0x53849cb
    domain: light
  - type: turn_on
    device_id: 835a0e84c17bae2b3c8f33e419b00d3a
    entity_id: light.yeelight_ct_bulb_0x536342f
    domain: light
  - type: turn_on
    device_id: 290958963b40a3bb646d32282df5c60d
    entity_id: light.yeelight_ct_bulb_0x537007d
    domain: light
  - type: turn_on
    device_id: d1c5e1cf77ca2f26cb41d7ee3e2b5fb5
    entity_id: light.yeelight_color_0x52be222
    domain: light
  mode: single
*/
#define MAX_ARG 10

enum TypePlat {
  STATE,
};

enum TrigEv {
  OFF,
  ON,
  OFF_ON,
  ON_OFF
};

char enu2Yaml_TrigEv[][] = {
  "",
  "",
  "from: 'off' \n\rto: 'on'",
  ""
};

enum NextBooleanCond {
  STOP,
  AND,
  OR
};

struct Trig_ent {
  char name[];
  enum TypePlat platform;
  enum TrigEv is;
};

struct Trigger_t {
  int trig_ent_num;
  struct Trig_ent entities[5];
  enum NextBooleanCond cond[4]
}

char enu2Yaml_platform[][] = {
  "state"
};

void CreateTrigger(struct Trigger_t *tri)
{
  int i = 0;

  printf("trigger:\n\r  ");
  for(i=0;i<tri->trig_ent_num;i++){
    printf("- platform: %s\n\r", enu2Yaml_platform[tri->entities[i].platform]);
    printf("  entity_id: %s\n\r",tri->entities[i].name);
    printf(" %s\n\r",enu2Yaml_TrigEv[tri->entities[i].is]);
    printf("\n\r");
  }
}