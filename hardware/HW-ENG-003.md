# 🛠️ HW-ENG-003: Horizontal PEHD Biofermenter and Submerged Fermentation Vessel

* **Document Code:** HW-ENG-003
* **Version:** 1.0
* **System Target:** Low-Cost Submerged Liquid Fermentation for PGPR and Microbial Inoculants
* **Capacity:** 50L – 200L Batch Volume
* **Licensing:** CERN Open Hardware Licence Version 2 - Permissive (CERN-OHL-P)
* **Author:** SARL B.A. LAB — Hardware & Engineering Unit

---

## 📌 1. Technical Overview & Fluid Dynamics

This document specifies the mechanical assembly, sanitary sealing, chemical sterilization, and sensor instrumentation for a horizontal High-Density Polyethylene (PEHD / HDPE) biofermenter. Designed for scalable production of Plant Growth-Promoting Rhizobacteria (PGPR, e.g., *Bacillus spp.*) and biological liquid inoculants, the horizontal vessel design maximizes liquid-gas contact surface area and improves oxygen transfer rate ($k_L a$) while utilizing food-grade, highly inert PEHD materials.

### Oxygen Transfer Rate ($k_L a$) & Aeration Mechanics

For aerobic microbial strains, dissolved oxygen ($DO$) is the primary limiting factor. The volumetric oxygen transfer rate ($OTR$) is governed by:

$$OTR = k_L a \cdot (C^* - C_L)$$

Where:
* $k_L a$ = Volumetric mass transfer coefficient ($\text{h}^{-1}$)
* $C^*$ = Oxygen saturation concentration in liquid phase ($\text{mg/L}$)
* $C_L$ = Actual dissolved oxygen concentration ($\text{mg/L}$)

To maximize $k_L a$ without thermomechanical damage to PEHD, air is injected through a sintered stainless-steel micro-sparger ($10 - 20\ \mu\text{m}$ pore size) at an operational airflow rate of $0.5 - 1.0\ \text{VVM}$ (Volume of Air per Volume of Liquid per Minute). Horizontal liquid distribution increases bubble residence time relative to fluid depth.

---

## 🔩 2. Bill of Materials (BOM)

| Component | Technical Specifications | Qty | Function |
| :--- | :--- | :--- | :--- |
| **Vessel Body** | Horizontal Food-Grade PEHD drum ($100\text{L}$), wall thickness $\ge 4\text{mm}$ | 1 | Primary bio-reaction chamber |
| **Micro-Sparger** | Sintered Stainless Steel 316L, $20\ \mu\text{m}$ porous element, $1/2\text{"}$ NPT thread | 1 | Fine bubble air diffusion |
| **Air Exhaust Filter** | Autoclavable PTFE hydrophobic membrane filter, $0.22\ \mu\text{m}$ | 2 | Exhaust sterile boundary & bio-containment |
| **Sanitary Ports** | Tri-Clamp $1.5\text{"}$ or $2\text{"}$ Food-Grade PEHD/316L bulkhead fittings | 4 | Inoculation, sampling, and sensor ports |
| **Sampling Valve** | Stainless Steel 316L Sanitary Flame-Sterilizable Sampling Valve | 1 | Sterile aseptic sample extraction |
| **Aeration Pump** | Oil-free diaphragm air pump ($\ge 60\ \text{L/min}$, $0.04\ \text{MPa}$) | 1 | Aerobic air pressure supply |
| **Liquid Transfer Pump**| Peristaltic dosing pump (Silicone tubing $8\text{mm}$ ID) | 2 | Acid/Base dosing and seed inoculation |
| **Sealing Gaskets** | Food-Grade Viton / EPDM O-rings and Tri-Clamp silicone gaskets | 1 set | Gas-tight and chemical-proof seal |

```text
               Exhaust PTFE Filter (0.22µm)
                          │
  ┌───────────────────────┴───────────────────────┐
  │  [Inoculation Port]        [pH / Temp Sensor]  │  <-- PEHD Vessel Body
  │                                               │
  │ ~ ~ ~ ~ ~ ~ ~ ~ Liquid Culture ~ ~ ~ ~ ~ ~ ~ ~│  <-- Liquid Phase (70% V_max)
  │                                               │
  └───────────────────────┬───────────────────────┘
                          │
            Micro-Sparger (Sintered 316L) <── Sterile Air Input (0.22µm filtered)
⚙️ 3. Assembly & Sealing Validation Protocol
Phase A: Bulkhead Machining & Fitting Installation
Drill precision port holes into the upper quadrant of the PEHD vessel using carbide hole-saws.
Deburr cut edges and sanitize with $70\%$ ethanol.Install food-grade Tri-Clamp / NPT bulkhead fittings using dual EPDM gaskets (one interior, one exterior).
 Tighten compression nuts to specified torque ($12\ \text{N}\cdot\text{m}$).
Phase B: Micro-Sparger Positioning
Position the micro-sparger along the lowest horizontal central axis of the vessel.
Secure the air feed line using reinforced silicone tubing capable of withstanding $2.0\ \text{bar}$ pressure.
Phase C: Pneumatic Hydro-Pressure TestFill the vessel to $100\%$ capacity with tap water and seal all sanitary ports.
Pressurize the vessel with clean air to $0.3\ \text{bar}$ ($30\ \text{kPa}$) above atmospheric pressure.Apply soapy water solution to all threaded joints, gaskets, and port welds.
Acceptance Metric: Zero bubble formation over a 30-minute hold period.🧼

🧼 4. Chemical Sanitization & Sterilization (CIP)
PEHD undergoes thermal deformation above $80^\circ\text{C}$ and cannot be steam-autoclaved.
 Sanitation relies on Clean-in-Place (CIP) chemical protocols.

CIP Sanitation Cycle
[ Detergent Wash (NaOH 1%) ] ──> [ RO Water Rinse ] ──> [ Peracetic Acid Sanitization (0.2%) ] ──> [ Sterile Water Rinse ]

Alkaline Wash: Recirculate 1.0% (w/v) NaOH solution at 50 
∘
 C for 30 minutes to remove organic residues and bio-films.

Rinse: Flush with Reverse Osmosis (RO) water until exit pH<8.0.

Cold Cold-Sterilization: Fill vessel spray ball or recirculate 0.2% (v/v) Peracetic Acid (CH 
3
​
 CO 
3
​
 H) or 3% H 
2
​
 O 
2
​
  for 45 minutes.

Final Rinse & Purge: Drain solution thoroughly under positive pressure with sterile 0.22 μm filtered air.

📊 5. Instrumentation & ESP32 Telemetry Integration
Sensor / Actuator	Signal Type	Range / Spec	Function
pH Probe	Analog (0−3.3V via BNC module)	pH 0.00−14.00	Continuous monitoring for acid/base dosing
DS18B20 Temp Probe	OneWire Digital (GPIO)	−10 
∘
 C to +85 
∘
 C±0.5 
∘
 C	Temperature control loop
Dissolved Oxygen (DO)	Galvanic / Optical DO module	0−200% saturation	Air pump frequency modulation
Peristaltic Relays	GPIO Digital Output (Active LOW)	12V DC/2A drive	Automated pH adjustment dosing
📜 Operational Safety Notes
Maximum Vessel Working Pressure: Do not exceed 0.5 bar (50 kPa). Install a calibrated 0.4 bar mechanical pressure relief valve on the exhaust manifold.

Chemical Handling: Wear nitrile gloves, face shield, and chemical apron when preparing Peracetic Acid and Concentrated NaOH wash solutions.
