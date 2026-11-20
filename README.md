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

## Build and flash

Every push or pull request that touches `config/**` or `build.yaml` builds the firmware in GitHub
Actions (`Build ZMK firmware (nix)`). Download the `.uf2` files from the run's artifacts.

To flash a half: hold the BOOT button while you plug it in (or double-tap reset), then copy the
matching `.uf2` to the `RPI-RP2` drive. Flash both halves. The left half is the central and connects
to the computer.

For a local build environment, see urob's
[workspace notes](https://github.com/urob/zmk-config#part-i-the-workspace) (`just init`, then
`just build silakka54`).
