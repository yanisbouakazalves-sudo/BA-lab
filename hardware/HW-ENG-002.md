# 🛠️ HW-ENG-002: Flame-Cap Kon-Tiki Pyrolysis Kiln & Biochar Thermo-Chemical Activation

* **Document Code:** HW-ENG-002
* **Version:** 1.0
* **System Target:** Biomass Pyrolysis & Porous Carbon Matrix Production for Terra Preta / PGPR Carrier
* **Licensing:** CERN Open Hardware Licence Version 2 - Permissive (CERN-OHL-P)
* **Author:** SARL B.A. LAB — Hardware & Soil Regeneration Unit

---

## 📌 1. Technical Overview & Thermodynamics

This document defines the design specifications, operation, and wet-activation protocol for a deep-cone Flame-Cap Kon-Tiki Pyrolysis Kiln. The kiln converts agricultural residues (prunings, straw, nutshells) into high-surface-area biochar ($SSA \ge 300\ \text{m}^2/\text{g}$) through oxygen-starved high-temperature thermochemical decomposition ($500^\circ\text{C} - 650^\circ\text{C}$).

### Thermodynamic Principle

The $63^\circ$ conical geometry forms a continuous rising flame curtain over the pyrolyzing bed. This curtain burns all volatile pyrolytic gases ($\text{CO}$, $\text{CH}_4$, tar vapors) as they exit the biomass, consuming incoming oxygen and maintaining an anoxic zone beneath the flame:

$$\text{Biomass} \xrightarrow[\Delta, \text{ No O}_2]{500^\circ\text{C} - 650^\circ\text{C}} \text{Biochar (C)} + \text{Bio-oil (tars)} + \text{Syngas } (\text{CO}, \text{H}_2, \text{CH}_4)$$

Quenching the biochar at peak core temperature ($>600^\circ\text{C}$) with an organic/nutrient hydrolysate drives liquid deep into the microscopic pores via thermal contraction and vapor vacuum condensation, achieving simultaneous quenching and biological activation.

---

## 🔩 2. Bill of Materials (BOM) & Geometry

| Component | Technical Specifications | Qty | Function |
| :--- | :--- | :--- | :--- |
| **Kiln Body** | Structural Carbon Steel plate ($3.0\text{mm}$ thickness), $1200\text{mm}$ top rim diameter, $63^\circ$ cone angle | 1 | Pyrolysis chamber |
| **Drainage Valve** | $2\text{-inch}$ High-Temperature Ball Valve (Brass/Steel) with female NPT threads | 1 | Liquid quench drainage & extraction |
| **Rim Ring** | Tubular steel ring ($25\text{mm}$ square tube) welded to top rim | 1 | Structural rigidity & wind shield |
| **Quenching Manifold** | Perforated steel pipe ring ($1/2\text{-inch}$) mounted below upper rim | 1 | Uniform liquid quenching injection |
| **Support Legs** | Heavy-duty angle iron ($40 \times 40 \times 4\text{mm}$), $300\text{mm}$ clearance | 3 | Stability & valve clearance |

```text
       Top Rim (Ø 1200mm)
  \=========================/   <-- Flame Curtain (Combustion of Gases)
   \                       /
    \   Anoxic Pyrolysis  /     <-- Pyrolyzing Layer (500°C - 650°C)
     \       Zone        /
      \                 /
       \===============/        <-- Quenching / Drainage Valve (2")


⚙️ 3. Pyrolysis Operational
ProtocolPhase A: Fire Initiation & Bed FoundationPlace small, dry kindling ($<20\%\text{ moisture}$) at the bottom of the cone.
Ignite from the top to establish an immediate upper flame layer. Wait until the initial wood layer is glowing red without visible smoke ($\sim 10\text{ minutes}$).
Phase B: Continuous Layer FeedingSpread a uniform layer of biomass ($3 - 5\text{cm}$ thick) over the glowing embers.Observe the birth of yellow/translucent flames over the new biomass layer.
Critical Rule: Add the next biomass layer only when the previous layer turns gray/ash-coated on its upper surface. Do not overload to avoid suppressing the flame curtain.
Continue sequential feeding until the cone is filled to $90\%$ volume.
Phase C: Wet-Nutrient Quenching & ActivationPrepare the quenching solution in a secondary reservoir:Quenching Base: $200\text{L}$ Water + $10\%\text{ (v/v)}$  Seaweed Hydrolysate + $2\%\text{ (w/v)}$ Humic Extract.As the final pyrolysis layer reaches $600^\circ\text{C}$, connect the quenching line to the injection manifold.Inject the liquid rapidly into the glowing biochar matrix.
Maintain liquid submergence for 30 minutes to saturate internal micropores.Drain the nutrient-enriched effluent through the 2-inch bottom valve into storage for use as a fertigation liquid.
📊 4. Quality Control & Biochar CharacterizationParameterTest Method / MetricTarget ValueCorrective ActionpH ($1:10\text{ H}_2\text{O}$)Calibrated pH Probe$7.5 - 8.8$If $\text{pH} > 9.5$, increase quenching volume or neutralize with citric acidVolatile Matter ContentProximate Analysis ($950^\circ\text{C}$ muffle furnace)$< 20\%$If $>25\%$, residence time was insufficient; decrease feeding rateWater Holding Capacity (WHC)Gravimetric saturation assay$\ge 250\%\text{ (w/w)}$Ensure crushing/milling particle size is $< 2\text{mm}$Ash ContentDry Combustion ($550^\circ\text{C}$, 4 hours)$< 10\%$Avoid soil/dirt inclusion in raw biomass input📜 Mechanical Maintenance & SafetyEPI Requirements: Heat-resistant leather welding gloves, full face shield, FFP3 dust respirator during biochar crushing.
Storage: Store crushed biochar in breathable polypropylene sacks under dry conditions to prevent spontaneous thermal oxidation.
