# jellydn's zmk-config

ZMK firmware for my split keyboards, forked from
[urob/zmk-config](https://github.com/urob/zmk-config). The keymap is a port of my Vial layout
([miryoku-silakka54-layout](https://github.com/jellydn/miryoku-silakka54-layout),
[visual reference](https://kb.itman.fyi/index-graphite.html)): Graphite base, GACS home-row mods,
Miryoku-style thumb layers.

![Keymap](draw/silakka54.svg)

## Keyboards

| Keyboard  | Status    | Build target                             | Notes                                       |
| --------- | --------- | ---------------------------------------- | ------------------------------------------- |
| Silakka54 | supported | `rpi_pico//zmk` + `silakka54_left/right` | Onboard RP2040, full-duplex wired split     |
| Corne v4.1 | planned  | —                                        | Needs single-wire (half-duplex) wired split, not yet in ZMK for RP2040 |

## Keymap

- **Base**: Graphite with home-row mods `Gui Alt Ctrl Shift` on `N R T S` and the mirror,
  `Shift Ctrl Alt Gui`, on `H A E I`
  (urob's "timeless" HRMs: a hold resolves only with a key on the other hand or a thumb).
- **Thumbs** (left to right): `=`, `Space`/Nav, `Tab`/Mouse, `Enter`/Sym, `Bksp`/Num, `;`.
- **Layers**: Nav (arrows, Home/End, PgUp/PgDn), Mouse (mouse keys, Cmd shortcuts, one-shot Fn),
  Sym (shifted Num), Num (numpad), Fn (F-keys, media). `Lock` keeps the current layer on until you
  press it again.
- **Combos** (base layer only):

  | Keys    | Output       | Keys  | Output       |
  | ------- | ------------ | ----- | ------------ |
  | B L     | Esc          | F O   | sticky Meh   |
  | L D     | sticky Gui   | F U   | Esc          |
  | B L D   | Cmd+Q        | O U   | `'`          |
  | L W     | Enter        | . -   | sticky Meh   |
  | D W     | sticky Hyper | Q X   | Cmd+X        |
  | X M     | Cmd+C        |       |              |

- **Graphite shifted pairs** (base layer): Shift+`'` = `_`, Shift+`,` = `?`, Shift+`-` = `"`,
  Shift+`/` = `<`.
- **Mouse keys** match the Vial mouse key settings (linear ramp to 4000 px/s in 600 ms; wheel to
  100 steps/s in 3.2 s).

## Layout of the repo

| What                               | Where                                |
| ---------------------------------- | ------------------------------------ |
| Layers, HRMs, thumb keys           | `config/base.keymap`                 |
| Combos                             | `config/combos.dtsi`                 |
| Per-board entry keymap and config  | `config/<board>.keymap`, `.conf`     |
| Silakka54 shield (pins, layout)    | `config/boards/shields/silakka54/`   |
| Build targets                      | `build.yaml`                         |
| Keymap drawing                     | `draw/` (rendered by the Draw workflow or `just draw`) |

`base.keymap` holds every layer once, for the 54-key Silakka54. Another board (such as the Corne)
gets a small `config/<board>.keymap` that defines `ZMK_BASE_LAYER` to drop the number row or add
extra keys, then includes `base.keymap`. Combos and HRM trigger keys use the
[zmk-helpers](https://github.com/urob/zmk-helpers) key labels, so they move with the layout.

## Build

Every push or pull request that touches `config/**` or `build.yaml` builds the firmware in GitHub
Actions (`Build ZMK firmware (nix)`).

For a local build environment, see urob's
[workspace notes](https://github.com/urob/zmk-config#part-i-the-workspace) (`just init`, then
`just build silakka54`).

## How to flash

### Silakka54 (ZMK)

**Where the buttons are.** Each half has an
[RP2040-Zero](https://www.waveshare.com/wiki/RP2040-Zero) controller. Its two small buttons sit
next to its USB-C port, and the board labels them BOOT and RESET:

```text
        ┌───[ USB-C ]───┐
        │ (BOOT) (RESET)│   ← labels are printed next to each button
        │               │
        │   RP2040-Zero │
        └───────────────┘
```

On the original Silakka54 build the right controller is mounted upside down, so its buttons face the
PCB. Press them with a non-metal stick (the
[Silakka54 wiki](https://github.com/Squalius-cephalus/silakka54/wiki/Firmware-Update) has a
3D-printable tool).

**Steps**

1. Open the latest green `Build ZMK firmware (nix)` run in the Actions tab and download the
   `firmware` artifact. It holds `silakka54_left-rpi_pico__zmk-zmk.uf2` and
   `silakka54_right-rpi_pico__zmk-zmk.uf2`.
2. Unplug the USB cable, then unplug the TRRS cable between the halves.
3. Left half: hold BOOT and plug the USB cable into the left half, then let go of BOOT. If it is
   already plugged in, hold BOOT, press RESET, then let go of BOOT.
4. A drive named `RPI-RP2` opens. Copy `silakka54_left-…uf2` to it. The drive closes by itself when
   the flash is done.
5. Unplug the USB cable. Do steps 3 and 4 on the right half with `silakka54_right-…uf2`.
6. With the USB cable unplugged, connect the TRRS cable.
7. Plug the USB cable into the **left** half. The left half is the central; the right half gets
   power and sends its keys through the TRRS cable.

**Troubleshooting**

- One half does not type: flash that half again with its own file. Left and right files are
  different; do not swap them.
- No `RPI-RP2` drive: use a USB cable that carries data, plug in straight to the computer, and try
  BOOT + RESET again.
- Never plug in or unplug the TRRS cable while the USB cable is connected. This can short the
  controllers.
