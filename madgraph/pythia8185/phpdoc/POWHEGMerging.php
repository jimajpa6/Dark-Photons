<html>
<head>
<title>POWHEG Merging</title>
<link rel="stylesheet" type="text/css" href="pythia.css"/>
<link rel="shortcut icon" href="pythia32.gif"/>
</head>
<body>

<script language=javascript type=text/javascript>
function stopRKey(evt) {
var evt = (evt) ? evt : ((event) ? event : null);
var node = (evt.target) ? evt.target :((evt.srcElement) ? evt.srcElement : null);
if ((evt.keyCode == 13) && (node.type=="text"))
{return false;}
}

document.onkeypress = stopRKey;
</script>
<?php
if($_POST['saved'] == 1) {
if($_POST['filepath'] != "files/") {
echo "<font color='red'>SETTINGS SAVED TO FILE</font><br/><br/>"; }
else {
echo "<font color='red'>NO FILE SELECTED YET.. PLEASE DO SO </font><a href='SaveSettings.php'>HERE</a><br/><br/>"; }
}
?>

<form method='post' action='POWHEGMerging.php'>
 
<h2>POWHEG Merging</h2> 
 
POWHEG [<a href="Bibliography.php" target="page">Nas04</a>] in its character is very much like a parton shower, 
with a Sudakov factor arising from the ordering of emissions. Both 
POWHEG-BOX [<a href="Bibliography.php" target="page">Ali10</a>] and PYTHIA are based on a combined evolution 
of ISR and FSR in <i>pT</i>-related "hardness" variables, and thus are 
kindred spirits. The hardness definitions differ, however. Frequently we 
will therefore need to distinguish between POWHEG-hardness and 
PYTHIA-hardness in the following. 

<p/> 
The simplest merging solution, of continuing the PYTHIA shower at the LHA 
<code>scale</code> hardness where POWHEG leaves off, is obtained if you 
set <code>SpaceShower:pTmaxMatch = 1</code> and 
<code>TimeShower:pTmaxMatch = 1</code>. But then mismatches are bound to 
happen: some regions may be doublecounted, while others may not be counted 
at all. Depending on the choice of hardness, such mismatches might be small. 
  
<p/> 
There are no guarantees, however, so a (hopefully) more accurate merging
scheme is coded up in the <code>examples/main31</code> files. Here we would 
like to discuss the (POWHEG-specific) input settings for 
<code>main31.cc</code>, and attempt to give some recommendations on how to 
use the main program to perform a matching of POWHEG-BOX with PYTHIA 8. 
The main source of documentation is <code>main31.cmnd</code>, however. 
 
<p/> 
POWHEG-BOX inputs contain Born-like events (with no resolved emission) and 
Real-type events (containing an additional parton). The mismatch between 
POWHEG-hardness and PYTHIA-hardness can be minimised if the PYTHIA shower 
knows 
<br/>a) The POWHEG-hardness criterion (through which the separation of Born- 
and Real-like events is defined), and 
<br/>b) The POWHEG-hardness value (which separates Born- and Real-like 
events). 
<br/>If these definitions are known, then 
PYTHIA can fill missing phase space regions through vetoed showering: let 
the shower sweep over the full phase space, using its PYTHIA-hardness 
ordering, and use the POWHEG-hardness to veto those emissions that POWHEG 
should already have covered. This is only possible since the 
POWHEG-hardness criterion and the shower ordering criterion are very 
similar. In the more general case a truncated showering would be needed
[<a href="Bibliography.php" target="page">Nas04</a>]. 
 
<p/> 
For vetoed showering, it is necessary to define the POWHEG-hardness criterion 
in <code>main31.cc</code>. In the presence of multiple partons, the definition 
quickly becomes complicated, and allows for different choices. Similar 
decisions have already been made in the implementation of POWHEG, one example 
being the choice in defining which "hardness value" is transferred as 
POWHEG-hardness, e.g. by deciding if the "singular regions" of the FKS or the 
CS approach are used. If the POWHEG-hardness definition were to be changed,
or extended to more objects, the <code>main31.cc</code> code would need to
be modified accordingly.  
 
<p/> 
<code>main31.cc</code> is designed to be very flexible, and allows access 
to many possible choices. However, this flexibility means that many parameters 
can be changed, potentially leading to confusion. Thus, recommendations might 
prove helpful. All mistakes and inaccuracies rest with the author. 
 
<p/> 
We recommend the usage of vetoed showers. This means using 
<br/> &nbsp; &nbsp; &nbsp;&nbsp; &nbsp; <code>POWHEG:veto = 1</code> 
<br/> 
This means that PYTHIA will sweep over the full phase space, and apply a veto 
on parton shower emissions for which the POWHEG-hardness separation between 
radiator and emission is above the POWHEG-hardness value of the current input 
event. The variation <code>POWHEG:veto = 0</code> can be used to assess 
how much phase space is under- or double-counted. 

<p/> 
To define the POWHEG-hardness criterion, use 
<br/> &nbsp; &nbsp; &nbsp;&nbsp; &nbsp; <code>POWHEG:pTdef = 1</code> 
<br/> 
Other values can be used by experts to assess variations. 

<p/> 
Both POWHEG-BOX and PYTHIA 8 generate emissions through a parton shower 
step, meaning that both programs have a clear definition of a radiator 
that emits particles, which is very similar (if not identical). 
To fix the ambiguity if the radiator or the emitted particle should be 
called "the emission", use 
<br/> &nbsp; &nbsp; &nbsp;&nbsp; &nbsp; <code>POWHEG:emitted = 0</code> 
<br/> 
More complicated choices can be used by experts. For instance, use 
<code>POWHEG:emitted = 2</code> to check the POWHEG-hardness of both 
radiator and emitted. 

<p/> 
To exhaustively fix the criterion by which to veto parton shower 
emissions, it is important to decide which partons/parton pairs 
are used to calculate the POWHEG hardness of a PYTHIA 8 emission. 
The minimal and recommended choice is 
<br/> &nbsp; &nbsp; &nbsp;&nbsp; &nbsp; <code>POWHEG:pTemt = 0</code> 
<br/> 
This means that only the POWHEG hardness w.r.t the radiating leg is 
checked, and recoil effects are neglected. This prescription should be 
very similar to how a hardness value is assigned to a Real-type event 
in the POWHEG-BOX, since in the (implementation of FKS in the) POWHEG-BOX, 
initial state splittings only have singular regions with the radiating 
initial state parton, and final state splittings only have singular 
regions w.r.t the radiating final state line. Other choices of 
<code>POWHEG:pTemt</code> are available. A warning is that the impact of 
changes can be huge, particularly for inputs with many jets. Other choices 
therefore should only be made by experts, and a high degree of caution 
is advised. 
 
<p/> 
It is furthermore necessary to decide on a value of the hardness criterion. 
POWHEG-BOX transfers this value in the <code>SCALUP</code> member of 
Les Houches Events, and we recommend using this value by setting 
<br/> &nbsp; &nbsp; &nbsp;&nbsp; &nbsp; <code>POWHEG:pThard = 0</code> 
<br/> 
As a variation, in order to estimate the uncertainty due this choice of 
POWHEG-hardness definition, it can be useful to also check 
<code>POWHEG:pThard = 2</code>. This will recalculate the POWHEG-hardness 
value as promoted in [<a href="Bibliography.php" target="page">Ole12</a>]. 
 
<p/> 
Finally, you need to decide how many emissions the vetoed shower should 
check after an allowed emission has been constructed. If the hardness 
definitions in POWHEG-BOX and PYTHIA 8 where identical, all checking could 
be stopped after the first allowed PS emission. To be prudent, we 
recommend setting 
<br/> &nbsp; &nbsp; &nbsp;&nbsp; &nbsp; <code>POWHEG:vetoCount = 3</code> 
<br/> 
which will then check up to three allowed emissions. Higher values of 
<code>POWHEG:vetoCount</code> have not lead to visible differences 
for the processes which have been tested.  

</body>
</html>
 
<!-- Copyright (C) 2014 Torbjorn Sjostrand --> 
